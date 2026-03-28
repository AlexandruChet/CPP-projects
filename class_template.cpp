#include <iostream>
#include <string>

template <class T>

class Arrays {
private:
    int len;
    T* arr;
public:
    Arrays(T* array, int len) {
        this->len = len;
        arr = new T[len];
        for (int i = 0; i < len; i++)
            *(arr + i) = *(array + i);
    }

    void get_console() {
        for (int i = 0; i < len; i++)
            std::cout << arr[i] << "";
        std::cout << std::endl;
    }

    T& operator[](int index) {
        return arr[index];
    }

    int size() const {
        return len;
    }

    void push_back(T value) {
        T* new_arr = new T[len + 1];
        for (int i = 0; i < len; i++)
            new_arr[i] = arr[i];
        new_arr[len] = value;

        delete[] arr;
        arr = new_arr;
        len++;
    }

    void remove_element(int index) {
        if (index < 0 || index >= len) return;

        T* new_arr = new T[len - 1];

        for (int i = 0, j = 0; i < len; i++) {
            if (i == index) continue;
            new_arr[j++] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        len--;
    }

    int find_element(T value) {
        for (int i = 0; i < len; i++)
            if (arr[i] == value) return i;
        return -1;
    }

    ~Arrays() {
        delete[] arr;
    }
};

int main() {
    int int_array[] = {1, 2, 3, 4, 5};

    Arrays<int> arr(int_array, 5);

    std::cout << "Start: ";
    arr.get_console();

    arr[1] = 10;
    arr.get_console();

    arr.push_back(5);
    arr.get_console();

    arr.remove_element(2);
    arr.get_console();

    int index = arr.find_element(10);
    std::cout << "Index of 10: " << index << std::endl;

    std::cout << "Size: " << arr.size() << std::endl;
    return 0;
};
