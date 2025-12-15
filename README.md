How to implement a package
1. Go to [xdsim-cbinds](https://github.com/25cst/xdsim-cbinds/)
2. Save the bindgen/c/xdsim-v0.h file to your working directory.
3. Create a new C file with the following content
   ```c
   // only include one of
   #define XDSIM_GATE // if you are creating a gate
   #define XDSIM_CONN // if you are creating a connection
   #define XDSIM_DATA // if you are creating a data type
   
   #include "xdsim-v0.h"
   ```
4. Go to the src/v0/component folder in the repo, and look at the functions in gate/connection/data.rs.
5. Implement all the unimplemented functions in your C file.
