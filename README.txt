--- token Project ---

 - How to Build -
   - just run `./build.sh`

 - After build -
   - The built smart contract is under the 'token' directory in the 'build' directory
   - You can then do a 'set contract' action with 'cleos' and point in to the './build/token' directory

 - Additions to CMake should be done to the CMakeLists.txt in the './src' directory and not in the top level CMakeLists.txt
