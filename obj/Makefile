###########################################################
## MakeFile by P.L. van der Jagt
## Can be used to compile CPU and GPU (cuda) code
## USER SPECIFIC DIRECTORIES ##

# CUDA directory:
CUDA_ROOT_DIR=/usr/local/cuda

##########################################################

## CC COMPILER OPTIONS ##

# CC compiler options:
CC=g++ -pthread
# CC_FLAGS=-Wall -g -std=c++2a -march=native -mmmx -msse -msse2 -fprefetch-loop-arrays -DDSFMT_MEXP=521 -DHAVE_SSE2
CC_FLAGS=-Wall -g -std=c++2a -march=native -mmmx -msse -msse2 -fprefetch-loop-arrays -DDSFMT_MEXP=521 -DHAVE_SSE2
CC_LIBS=

##########################################################

## NVCC COMPILER OPTIONS ##

# NVCC compiler options:
NVCC=nvcc
NVCC_FLAGS= #-g -G -Xptxas -v -Xcompiler -rdynamic -MMD
NVCC_LIBS=

# CUDA library directory:
CUDA_LIB_DIR= -L$(CUDA_ROOT_DIR)/lib64
# CUDA include directory:
CUDA_INC_DIR= -I$(CUDA_ROOT_DIR)/include -I/home/pjotr/Downloads/cuda-samples/Common
# CUDA linking libraries:
# CUDA_LINK_LIBS= -lcudart

##########################################################

## Project file structure ##

# Source file directory:
SRC_DIR = ../src

# Object file directory:
OBJ_DIR = ../obj

# Include header file diretory:
INC_DIR = -I ../include

##########################################################

## Make variables ##

# Target executable name:
EXE = Run

# Object files:
CPU_OBJS = Cell.o Genome.o Agent.o parameters.o random.o
# GPU_OBJS = AgentGPUkernel.o AgentGPU.o
MAIN = World.o

OBJS = $(CPU_OBJS) $(MAIN) #$(GPU_OBJS)

##########################################################

# # ## Compile ##
all: $(EXE)

# Link c++ and CUDA compiled object files to target executable:
$(EXE) : $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o ../bin/$@ $(CUDA_INC_DIR) $(CUDA_LIB_DIR) $(CUDA_LINK_LIBS)

# Compile C++ source files to object files:
%.o : $(SRC_DIR)/%.cc
	$(CC) $(CC_FLAGS) -c $< -o $@ $(INC_DIR)

# # Compile CUDA source files to object files:
%.o : $(SRC_DIR)/%.cu
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@ $(INC_DIR) $(NVCC_LIBS)

# Clean objects in object directory.
clean:
	$(RM) obj/* *.o *.d $(EXE)
