# WorkUtilities

Programm to quickly format, edit or rename a set of Files.

For Processing the function ProcessData is used and has to be changed.

Use example:

```cpp
void processData(files, filePaths) {
    vector<string> newFile;
    for(uint i = 0; i < files.size(); i++) {
        string newFileName = filePaths[i] + ".new";
        for(uint j = 0; j < files[i].size(); j++) {
            if(getFirstOccurence(files[i][j], "bpo-") == -1 && files[i][j] >= 4) {
                if(getFirstOccurence(files[i][j], "Python") != -1) {
                    newFile.push_back(files[i][j]);
                } else {
                    newFile.push_back("\t" + files[i][j]);
                }
            } else {
                if(getFirstOccurence(files[i][j], "memory") != -1 || getFirstOccurence(files[i][j], "leak") != -1) {
                    newFile.push_back(" ================= " + files[i][j]);
                }
            }
        }
    }
    writeOutData(newFileName, newFile);
}
```
-> searching all read-in files for lines with "bpo-" and larger than 5 characters  
&emsp;  -> if not check if line contains "Python"   
&emsp;&emsp;    -> if it does write line with '\t' in front of it in new File  
&emsp;&emsp;    -> if it doesnt write normal line  
&emsp;  -> if it contains "bpo-" check if lines also contains "memory" or "leak", then write line with " ================== " in new file  
    
Then finally print new File to real File in system with name_of_old_file.new   
