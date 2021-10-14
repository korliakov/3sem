#include <iostream>

template <typename T>
class Grid {
private:
    T *memory = nullptr;
    size_t x_size, y_size;

public:
    Grid(size_t x_size, size_t y_size): x_size(x_size), y_size(y_size) {

        memory = new T[x_size*y_size];

    }



    ~Grid() {

        delete [] memory;
    }



    T operator()(size_t x_idx, size_t y_idx) const {
        size_t a;
        T res;
        if (y_idx > 1) {a = x_idx + x_size*(y_idx-1) -1;}

        else {a = x_idx -1;}

        res = memory[a];
        
        return res;


    }





    Grid<T>& operator()(size_t x_idx, size_t y_idx, T num) { //ошибка
        size_t a;
        
        if (y_idx > 1) {a = x_idx + x_size*(y_idx-1) -1;}

        else {a = x_idx -1;}

        memory[a] = num;
        
        return *this;
    }

    size_t get_xsize() const {

        return x_size;
    }
    size_t get_ysize() const {

        return y_size;
    }

    Grid& operator=(T a) {



        for (size_t i = 0; i < x_size*y_size; i++) {
            memory[i] = a;
        }
        
        
        return *this;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream &out, const Grid<U> &grid);

    template <typename U>
    friend std::istream& operator>>(std::istream &in, const Grid<U> &grid);
};


template <typename T>
std::ostream& operator<<(std::ostream &out,  const Grid<T> &grid) {

    for (size_t i = 0; i < grid.y_size; i++) {
        for (size_t j = 0; j < grid.x_size; j++) {
            size_t a;
            if (i > 0) {a = j + grid.x_size*(i);}

            else {a = j;}
        
            out << grid.memory[a] << ' ';

        }
        out << "\n";
    }

    return out;
}


template <typename U>
std::istream& operator>>(std::istream &in, const Grid<U> &grid) {

    for (size_t i=0; i < grid.x_size*grid.y_size; i++) {

        in >> grid.memory[i];
    }

    return in;
}



int main() {

    Grid<int> grid(2, 2);
    grid = 5;
    size_t x_size = grid.get_xsize();

    grid(1, 1, 1);
    std::cout << grid;


}