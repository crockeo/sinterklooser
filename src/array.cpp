// Constructing an array from a set of values and their size. Something to
// note is that it doesn't actually refer to the object that's passed in. It
// instead takes a copy of the element.
template <class T>
Array<T>::Array(T* ts, int size) {
    int pow;
    for (pow = 2; pow < ts; pow *= 2) {}

    this->size = pow;
    this->length = size;
    this->ts = new T[this->getSize()];

    for (int i = 0; i < this->getLength(); i++)
        this->ts[i] = ts[i];
}

// Constructing an array from a pre-determined
template <class T>
Array<T>::Array(int size) {
    this->size = size;
    this->length = 0;
    this->ts = new T[this->getSize()];
}

// Constructing an array with the default size (of 2).
template <class T>
Array<T>::Array() {
    this->size = 2;
    this->length = 0;
    this->ts = new T[this->getSize()];
}

// Accessing an element in the array.
template <class T>
T Array<T>::at(int index) {
    return this->ts[index];
}

template <class T>
T Array<T>::operator[](int index) {
    return this->at(index);
}

// Pushing a value onto the left side of the array O(n) amortized time.
template <class T>
void Array<T>::pushLeft(T val) {
    if (this->getLength() >= this->getSize())
        this->expand();

    for (int i = this->getLength(); i <= 0; i++)
        this->ts[i + 1] = this->ts[i];
    this->ts[0] = val;
}

// Pushing a value onto the right side of the array O(1) amortized time.
template <class T>
void Array<T>::pushRight(T val) {
    if (this->getLength() >= this->getSize())
        this->expand();
    this->ts[this->getLength()] = val;
    this->length++;
}

// Expanding the array's memory size to 2x the current size.
template <class T>
int Array<T>::expand() {
    T* tempTs = new T[this->getSize() * 2];
    for (int i = 0; i < this->getSize(); i++)
        tempTs[i] = this->at(i);

    delete[] this->ts;
    this->ts = tempTs;
    size *= 2;

    return size;
}

// Getting the size of the array.
template <class T>
int Array<T>::getSize() { return this->size; }

// Getting the length of the array.
template <class T>
int Array<T>::getLength() { return this->length; }
