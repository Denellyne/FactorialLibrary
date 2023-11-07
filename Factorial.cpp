#include <thread>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

void factorialPartition(cpp_int& block2, cpp_int block1); 
cpp_int calculateFactorial(cpp_int& block1, cpp_int& block2, cpp_int& block3, cpp_int& block4, cpp_int& block5, cpp_int& block6);

cpp_int factorial(cpp_int numberGiven) {
    
    if (numberGiven > 5) {

        cpp_int block1, block2, block3, block4, block5, block6;
        block1 = numberGiven / 6;
        block2 = block1 + block1;
        block3 = block2 + block1;
        block4 = block3 + block1;
        block5 = block4 + block1;
        block6 = (block5 + block1) + (numberGiven % 6);

        return calculateFactorial(std::ref(block1), std::ref(block2), std::ref(block3), std::ref(block4), std::ref(block5), std::ref(block6));        
    }
    else {

        cpp_int result = 1;
        for (int i = 0;i < numberGiven; i++) result = result * (numberGiven - i);

        return result;
    }
}

//Private

void factorialPartition(cpp_int& block2, cpp_int block1) {

    cpp_int result = 1;
    for (cpp_int i = 0;i < block1;i++) result = result * (block2 - i);

    block2 = result;
}
cpp_int calculateFactorial(cpp_int& block1, cpp_int& block2, cpp_int& block3, cpp_int& block4, cpp_int& block5, cpp_int& block6) {

    std::thread thread1(factorialPartition, std::ref(block6), (block6 - block5));
    std::thread thread2(factorialPartition, std::ref(block5), block1);
    std::thread thread3(factorialPartition, std::ref(block4), block1);
    std::thread thread4(factorialPartition, std::ref(block3), block1);
    std::thread thread5(factorialPartition, std::ref(block2), block1);
    std::thread thread6(factorialPartition, std::ref(block1), block1);
    thread6.join();
    thread5.join();
    thread4.join();
    thread3.join();
    thread2.join();
    thread1.join();

    return block1 * block2 * block3 * block4 * block5 * block6;
}
