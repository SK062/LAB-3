#include <iostream>
#include <stdexcept>
class RealNumbers {
private:
    double* numbers;
    int size;
public:
    RealNumbers(int n) {
        if (n <= 0) {
            throw std::invalid_argument("Розмір повинен бути більше 0");
        }
        size = n;
        numbers = new double[size];
    }
    ~RealNumbers() {
        delete[] numbers;
    }
    void inputNumbers() {
        for (int i = 0; i < size; i++) {
            std::cout << "Введіть дійсне число " << i + 1 << ": ";
            std::cin >> numbers[i];
        }
    }
    double findMax() {
        double max = numbers[0];
        for (int i = 1; i < size; i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        return max;
    }


    double findMin() {
        double min = numbers[0];
        for (int i = 1; i < size; i++) {
            if (numbers[i] < min) {
                min = numbers[i];
            }
        }
        return min;
    }
    RealNumbers operator+(const RealNumbers& other) {
        if (size != other.size) {
            throw std::invalid_argument("Розміри масивів не співпадають");
        }
        RealNumbers result(size);
        for (int i = 0; i < size; i++) {
            result.numbers[i] = numbers[i] + other.numbers[i];
        }
        return result;
    }
    RealNumbers operator-(const RealNumbers& other) {
        if (size != other.size) {
            throw std::invalid_argument("Розміри масивів не співпадають");
        }
        RealNumbers result(size);
        for (int i = 0; i < size; i++) {
            result.numbers[i] = numbers[i] - other.numbers[i];
        }
        return result;
    }
    RealNumbers operator*(const RealNumbers& other) {
        if (size != other.size) {
            throw std::invalid_argument("Розміри масивів не співпадають");
        }
        RealNumbers result(size);
        for (int i = 0; i < size; i++) {
            result.numbers[i] = numbers[i] * other.numbers[i];
        }
        return result;
    }
    RealNumbers operator/(const RealNumbers& other) {
        if (size != other.size) {
            throw std::invalid_argument("Розміри масивів не співпадають");
        }
        RealNumbers result(size);
        for (int i = 0; i < size; i++) {
            if (other.numbers[i] == 0) {
                throw std::runtime_error("Ділення на нуль неможливе");
            }
            result.numbers[i] = numbers[i] / other.numbers[i];
        }
        return result;
    }
    double operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Індекс за межами масиву");
        }
        return numbers[index];
    }
};
int main() {
    try {
        int n;
        std::cout << "Введіть розмір масиву: ";
        std::cin >> n;
        RealNumbers array1(n);
        RealNumbers array2(n);
        std::cout << "Введіть елементи першого масиву:" << std::endl;
        array1.inputNumbers();
        std::cout << "Введіть елементи другого масиву:" << std::endl;
        array2.inputNumbers();
        RealNumbers sum = array1 + array2;
        RealNumbers diff = array1 - array2;
        RealNumbers product = array1 * array2;
        RealNumbers quotient = array1 / array2;
        std::cout << "Найбільше число в першому масиві: " << array1.findMax() << std::endl;
        std::cout << "Найменше число в другому масиві: " << array2.findMin() << std::endl;

        std::cout << "Сума масивів:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << sum[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Різниця масивів:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << diff[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Добуток масивів:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << product[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Частка масивів:" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << quotient[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }
    return 0;
}
