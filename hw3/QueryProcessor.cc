/*
 * Copyright 2011 Steven Gribble
 *
 *  This file is part of the UW CSE 333 course project sequence
 *  (333proj).
 *
 *  333proj is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  333proj is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 333proj.  If not, see <http://www.gnu.org/licenses/>.
 */

// Yufang Sun
// 1334960
// mandary@uw.edu

#include <iostream>
#include <algorithm>

#include "./QueryProcessor.h"

extern "C" {
  #include "./libhw1/CSE333.h"
}


namespace hw3 {

QueryProcessor::QueryProcessor(list<string> indexlist, bool validate) {
  // Stash away a copy of the index list.
  indexlist_ = indexlist;
  arraylen_ = indexlist_.size();
  Verify333(arraylen_ > 0);

  // Create the arrays of DocTableReader*'s. and IndexTableReader*'s.
  dtr_array_ = new DocTableReader *[arraylen_];
  itr_array_ = new IndexTableReader *[arraylen_];

  // Populate the arrays with heap-allocated DocTableReader and
  // IndexTableReader object instances.
  list<string>::iterator idx_iterator = indexlist_.begin();
  for (HWSize_t i = 0; i < arraylen_; i++) {
    FileIndexReader fir(*idx_iterator, validate);
    dtr_array_[i] = new DocTableReader(fir.GetDocTableReader());
    itr_array_[i] = new IndexTableReader(fir.GetIndexTableReader());
    idx_iterator++;
  }
}

QueryProcessor::~QueryProcessor() {
  // Delete the heap-allocated DocTableReader and IndexTableReader
  // object instances.
  Verify333(dtr_array_ != nullptr);
  Verify333(itr_array_ != nullptr);
  for (HWSize_t i = 0; i < arraylen_; i++) {
    delete dtr_array_[i];
    delete itr_array_[i];
  }

  // Delete the arrays of DocTableReader*'s and IndexTableReader*'s.
  delete[] dtr_array_;
  delete[] itr_array_;
  dtr_array_ = nullptr;
  itr_array_ = nullptr;
}

vector<QueryProcessor::QueryResult>
QueryProcessor::ProcessQuery(const vector<string> &query) {
  Verify333(query.size() > 0);
  vector<QueryProcessor::QueryResult> finalresult;

  // MISSING:
  HWSize_t i;
  for (i = 0; i < query.size(); i++) {
    vector<QueryProcessor::QueryResult> query_result = finalresult;
    std::string word = query[i];
    HWSize_t j;
    for (j = 0; j < arraylen_; j++) {
      IndexTableReader *ireader = itr_array_[j];  // get index
      DocTableReader *dreader = dtr_array_[j];  // get doc

      DocIDTableReader *direader = ireader->LookupWord(word);  // get docid

      if (direader == NULL) continue;

      list<docid_element_header> dlist = direader->GetDocIDList();
      for (auto itr = dlist.begin(); itr != dlist.end(); itr++) {
        docid_element_header header = *itr;
        std::string filename;
        dreader->LookupDocID(header.docid, &filename);  // get filename

        HWSize_t count = 0;
        // if the docid alreday in the list, then increase the rank
        while (count < finalresult.size()) {
          if (filename.compare(finalresult[count].document_name) == 0 && i != 0) {
            finalresult[count].rank += header.num_positions;
          }
          count++;
        }
        if (i == 0) {
          // if the docid not in the list, add it into list
          QueryResult cur = {filename, header.num_positions};
          finalresult.push_back(cur);
        }
      }
      delete direader;
    }

    // check if rank in document is  changed
    HWSize_t doc;
    for (doc = 0; doc < query_result.size(); doc++) {
      HWSize_t count = 0;
      while (count < finalresult.size()) {
        // if in the same document and also match the rank of it
        if ((query_result[doc].document_name.compare(finalresult[count].document_name) == 0)
            & (query_result[doc].rank == finalresult[count].rank)) {
            finalresult.erase(finalresult.begin() + count);
        }
        count++;
      }
    }
  }

  // Sort the final results.
  std::sort(finalresult.begin(), finalresult.end());
  return finalresult;
}

}  // namespace hw3
