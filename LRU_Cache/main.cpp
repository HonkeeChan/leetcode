#include <iostream>
#include <list>
#include <unordered_map>
#include <iterator>

using namespace std;

class LRUCache {
public:
    typedef list<pair<int, int> > CacheList;
    CacheList data;
    unordered_map<int, pair<int, CacheList::iterator> >  m;
    int maxSize;
    int curSize;
    LRUCache(int capacity) {
        curSize = 0;
        maxSize = capacity;
    }
    
    int get(int key) {
        unordered_map<int, pair<int, CacheList::iterator> >::const_iterator cit;
        if((cit = m.find(key)) != m.end()){
            cout << "can't find key: " << key << " erase key in list and then push at the end"<< endl;
            int value = (cit->second).first;
            m.erase(cit);
            data.erase((cit->second).second);

            data.push_back({key, value});
            CacheList::iterator it = --data.end();
            
            m.insert({key, {value, it}});

            
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        unordered_map<int, pair<int, CacheList::iterator> >::iterator it;
        if((it = m.find(key)) == m.end()){
            if(curSize == maxSize){
                int k = data.begin()->first;
                cout<< "data front: " << k << endl;
                auto it = m.find(k);
                m.erase(it);
                data.pop_front();
                curSize--;

            }
            data.push_back({key, value});
            CacheList::iterator it = --data.end(); 
            m.insert({key, {value, it}});
            curSize++;
        }else{

            m.erase(it);
            data.erase((it->second).second);
            data.push_back({key, value});
            CacheList::iterator it = --data.end();
            
            m.insert({key, {value, it}});
        }
        
    }
    void print(){
        cout << "data list: " << endl;
        //copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
        for(auto it = data.begin(); it != data.end(); ++it){
            cout << it->first << " ";
        }
        cout << endl;
        cout << "hash map: " << endl;
        //copy(m.begin(), m.end(), [](auto it) {ostream_iterator<int>(cout, " ")});
        for(auto it = m.begin(); it != m.end(); ++it){
            cout << it->first << " ";
        }
        cout << endl;
    }

};

int main(){
    LRUCache cache( 2 );

    cache.put(1, 1);
    cache.print();
    cache.put(2, 2);
    cache.print();
    cache.get(1);       // returns 1
    cache.print();
    cache.put(3, 3);    // evicts key 2
    cache.print();
    cache.get(2);       // returns -1 (not found)
    cache.print();
    cache.put(4, 4);    // evicts key 1
    cache.print();
    cache.get(1);       // returns -1 (not found)
    cache.print();
    cache.get(3);       // returns 3
    cache.print();
    cache.get(4);       // returns 4
    cache.print();
    

    return 0;
}

