# Caching Peformance

Dylan Fu

## Description

**Task 1:** Measures the difference in access time of the caches/memory:
  * Linear access
  * Random access

**Task 2:** Measure the difference in performance in matrix multiplication:
  * Naive implementation
  * Transpose secondary matrix, to make memory accesses contiguous
  * Implement blocking to maximise caches

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need a GCC compiler to compile the C files.

#### Mac

On Mac OS, this can be done through *Homebrew* or installing *XCode Command Line Tools*.  
Open up terminal and enter:

##### Homebrew
```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew doctor
brew update
brew install gcc
```
##### XCode
```
xcode-select --install
```

#### Linux

On Linux, this can be done by installing *GCC* or the *build-essentials* package.  
Open up terminal and enter:

##### GCC only
```
sudo apt install gcc
```
##### build-essentials package
```
sudo apt install build-essential
```

#### Windows

If you are on Windows, you can click [here](https://preshing.com/20141108/how-to-install-the-latest-gcc-on-windows/)

### Installing

Clone the repository to your local machine with the following command in terminal:

```
git clone https://github.com/dylanfu/caching-performance.git
```

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
