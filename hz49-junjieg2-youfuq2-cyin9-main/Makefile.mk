# Executable names:
EXE = airports
#TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o Airport.o Route.o bfs.o Dijkstra.o Centrality.o Projection.o test.o

# Compiler/linker comfig and object/depfile directory:
CXX = clang++
LD = clang++
OBJS_DIR = .objs

# Add standard CS 225 object files
OBJS += cs225/lodepng/lodepng.o cs225/HSLAPixel.o cs225/PNG.o

# -MMD and -MP asks clang++ to generate a .d file listing the headers used in the source code for use in the Make process.
#   -MMD: "Write a depfile containing user headers"
#   -MP : "Create phony target for each dependency (other than main file)"
#   (https://clang.llvm.org/docs/ClangCommandLineReference.html)
DEPFILE_FLAGS = -MMD -MP

# Provide lots of helpful warning/errors:
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

# Flags for compile:
CXXFLAGS += $(CS225) -std=c++14 -stdlib=libc++ -O0 $(WARNINGS) $(DEPFILE_FLAGS) -g -c

# Flags for linking:
LDFLAGS += $(CS225) -std=c++14 -stdlib=libc++ -lc++abi

# Rule for `all` (first/default rule):
all: $(EXE)

# Rule for linking the final executable:
# - $(EXE) depends on all object files in $(OBJS)
# - `patsubst` function adds the directory name $(OBJS_DIR) before every object file
$(EXE): output_msg $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS))
	$(LD) $(filter-out $<, $^) $(LDFLAGS) -o $@


# Ensure .objs/ exists:
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/cs225
	@mkdir -p $(OBJS_DIR)/cs225/catch
	@mkdir -p $(OBJS_DIR)/cs225/lodepng

# Rules for compiling source code.
# - Every object file is required by $(EXE)
# - Generates the rule requiring the .cpp file of the same name
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Additional dependencies for object files are included in the clang++
# generated .d files (from $(DEPFILE_FLAGS)):
-include $(OBJS_DIR)/*.d
-include $(OBJS_DIR)/cs225/*.d
-include $(OBJS_DIR)/cs225/catch/*.d
-include $(OBJS_DIR)/cs225/lodepng/*.d

# Custom Clang version enforcement Makefile rule:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

output_msg: ; $(CLANG_VERSION_MSG)

# Standard C++ Makefile rules:
clean:
	rm -rf $(EXE) $(TEST) $(OBJS_DIR) $(CLEAN_RM) *.o *.d

tidy: clean
	rm -rf doc

.PHONY: all tidy clean output_msg