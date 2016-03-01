#include <iostream>
#include <boost/filesystem.hpp>
#include <leveldb/db.h>
#include <leveldb/cache.h>
#include <leveldb/filter_policy.h>
#include "utils.h"
#include "dbwrapper.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: deobfuscate /path/to/db";
        return 1;
    }

    boost::filesystem::path path = boost::filesystem::path(argv[1]);

    CDBWrapper db{path, 1000, false};

    CDBIterator *iter = db.NewIterator();

    for(iter->SeekToFirst();iter->Valid();iter->Next()) {

        std::string key;
        iter->GetKey(key);
        std::string value;
        iter->GetValue(value);
//        db.Write(key,value);
    }
    return 0;
}