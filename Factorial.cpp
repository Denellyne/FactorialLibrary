#include <thread>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

void factorialBlock1(cpp_int& block1) {
    cpp_int resultA = 1;
    for (cpp_int i = 0;i < block1;i++) {
        resultA = resultA * (block1 - i);
    }
    block1 = resultA;
}
void factorialBlock2(cpp_int& block2, cpp_int block1, cpp_int numberGiven) {
    cpp_int resultB = 1;
    cpp_int difference = block2 - block1;
    for (cpp_int i = 0;i < difference;i++) {
        resultB = resultB * (block2 - i);
    }
    block2 = resultB;
}
void factorialBlock6(cpp_int& block2, cpp_int block1) {

    cpp_int resultF = 1;
    cpp_int difference = block2 - block1;
    for (cpp_int i = 0;i < difference;i++) {
        resultF = resultF * (block2 - i);
    }
    block2 = resultF;
}
cpp_int calculateFactorial(cpp_int& block1, cpp_int& block2, cpp_int& block3, cpp_int& block4, cpp_int& block5, cpp_int& block6, cpp_int& numberGiven) {

    cpp_int result;
    std::thread thread1(factorialBlock6, std::ref(block6), block5);
    std::thread thread2(factorialBlock2, std::ref(block5), block4, numberGiven);
    std::thread thread3(factorialBlock2, std::ref(block4), block3, numberGiven);
    std::thread thread4(factorialBlock2, std::ref(block3), block2, numberGiven);
    std::thread thread5(factorialBlock2, std::ref(block2), block1, numberGiven);
    std::thread thread6(factorialBlock1, std::ref(block1));
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    result = block1 * block2 * block3 * block4 * block5 * block6;
    return result;
}
void factorial(cpp_int x,cpp_int &factorial) {
    cpp_int block1, block2, block3, block4, block5, block6;
    cpp_int result;
    cpp_int remainder = x % 6;
    block1 = x / 6;
    block2 = (x / 6) + block1;
    block3 = (x / 6) + block2;
    block4 = (x / 6) + block3;
    block5 = (x / 6) + block4;
    block6 = (x / 6) + block5;

    if (x > 5) {
        switch (remainder.convert_to<int>()) {
        case 0:
            
            factorial = calculateFactorial(std::ref(block1), std::ref(block2), std::ref(block3), std::ref(block4), std::ref(block5), std::ref(block6), std::ref(x));
            break;
        case 1:
            block6++;
            factorial = calculateFactorial(std::ref(block1), std::ref(block2), std::ref(block3), std::ref(block4), std::ref(block5), std::ref(block6), std::ref(x));
            break;
        case 2:
            block5++;
            block6++;
            factorial = calculateFactorial(std::ref(block1), std::ref(block2), std::ref(block3), std::ref(block4), std::ref(block5), std::ref(block6), std::ref(x));
            break;
        case 3:
            block4++;
            block5++;
            block6++;
            factorial = calculateFactorial(std::ref(block1), std::ref(block2), std::ref(block3), std::ref(block4), std::ref(block5), std::ref(block6), std::ref(x));
            break;
        case 4:
            block3++;
            block4++;
            block5++;
            block6++;
            factorial = calculateFactorial(std::ref(block1), std::ref(block2), std::ref(block3), std::ref(block4), std::ref(block5), std::ref(block6), std::ref(x));
            break;
        case 5:
            block2++;
            block3++;
            block4++;
            block5++;
            block6++;
            factorial = calculateFactorial(std::ref(block1), std::ref(block2), std::ref(block3), std::ref(block4), std::ref(block5), std::ref(block6), std::ref(x));
            break;
        }
    }
    else {
        cpp_int result = 1;
        for (cpp_int i = 0;i < x; i++) {
            result = result * (x - i);
        }
        factorial = result;
    }

}
