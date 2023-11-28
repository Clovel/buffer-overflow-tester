# buffer-overflow-tester

This is a C project that tests buffer overflow and shell execution vulnerabilities. It uses the CMake build system.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You need to have the following software installed on your machine:

- GCC
- CMake
- Make
- Python 3 (Python 2 ok, but adapt the script beforehand)

### OS settings

1. Disable ASLR

   ```bash
   sudo su - root
   echo "0" > /proc/sys/kernel/randomize_va_space
   ```

2. Disable stack protection

   Check that the `-fno-stack-protector` flag is present in the `CMakeLists.txt` file's build flags.

3. Compile the project

4. Give root permissions to file

   ```bash
   chown root:root build/src/SecurityTest-bin
   chmod u+s build/src/SecurityTest-bin
   ```

### Quick start

```bash
mkdir build
cd build && cmake .. && make; cd -
./buffer_overflow_test.sh

# OR

./build/src/SecurityTest-bin `python -c 'print ("A"*408)'`
```

### Building the Project

To build the project, follow these steps:

1. Open a terminal and navigate to the project directory.

2. Create a new directory for the build:

   ```bash
   mkdir build
   cd build
   ```

3. Run CMake to generate the build system:

   ```bash
   cmake ..
   ```

4. Run make to build the project:

   ```bash
   make
   ```

The executable will be located in the `build` directory or one of it's subdirectories.

### Running the Tests

To run the tests, follow these steps:

1. Open a terminal.

2. Run the tests:

   ```bash
   ./buffer_overflow_test.sh
   ```

## Authors

- Clovis Durand
