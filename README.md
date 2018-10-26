# Caching Peformance

Dylan Fu

## Description

**Task 1:** Measures the difference in access time of the caches between linear vs random access.
**Task 2:** Measure the difference in performance in matrix multiplication:
  * Naive Implementation
  * Transpose secondary matrix, to make memory accesses contiguous
  * Implement blocking to maximise caches

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need a GCC compiler to compile the C files, this can be done through homebrew or installing XCode Command Line Tools

**Homebrew**
```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew doctor
brew update
brew install gcc
```
**XCode**
```
xcode-select --install
```

### Installing

Clone the repository to your local machine with the following command in terminal:

```
git clone https://github.com/dfu88/caching-performance.git
```


End with an example of getting some data out of the system or using it for a little demo

## Running the tests

### Task 1
In terminal go to the *task_1* directory, then use these commands
```
make clean
make all
./cachetest1 --repetitions [NUMBER] --array_size [NUMBER]
./cachetest1 --repetitions [NUMBER] --array_size [NUMBER]
```

### Task 2
In terminal go to the *task_2* directory, then use these commands
```
make clean
make all
./matrix1
./matrix2
./matrix3
```
