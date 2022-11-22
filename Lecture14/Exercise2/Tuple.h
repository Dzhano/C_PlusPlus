#pragma once

template <class K, class V>
class Tuple {
private:
	K key;
	V value;

public:
    // constructor
    Tuple(K k, V v) {
        key = k;
        value = v;
    }

    // setters and getters
    void setKey(K& k) {
        key = k;
    }

    K& getKey() {
        return key;
    }

    void setValue(V& v) {
        value = v;
    }
    
    V& getValue() {
        return value;
    }
};
