# Variables
SOURCE_DIR=.
BUILD_DIR=./build
RUN=${BUILD_DIR}/SampleName

# Remove old build folder
rm -rf ${BUILD_DIR}
# Create new build folder
mkdir ${BUILD_DIR}
# Tell cmake where the source is and where to build it
cmake -S ${SOURCE_DIR} -B ${BUILD_DIR}
# Build project
make -C ${BUILD_DIR}
# Run program
./${BUILD_DIR}/SampleName 

# Doxygen
doxygen -g
doxygen
