# EECS-444-ComputerSecurity hw2part(2)
The original program is `PE-Import.exe`, the version that packed by virtual machine tool (VCprotect) is `PE-Import-vc+.exe`, the version that packed by VCprotect and UPX is `PE-Import-vc+upx.exe`.<br>
<br>SEE BELOW TO VIEW FULL REPORT<br>
## Step 1:<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/code.png)<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/result1.png)<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/result2.png)<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/result3.png)<br><br>
## Step 2:<br>
### in msvcp140.dll<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/msvcp140.png)<br>
`cout:`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/cout.png)<br>
`<<(+14 overload)`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/fout.PNG)<br>
(the code friction that define “<<”) <br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/foutcode.png)<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/foutimport.png)<br>
### in crt-runtime<br>
`System(“pause”)`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/system.PNG)<br><br>
Note: AS the program was written by C++, most API in my code can not be found in Imports. The reason may because msvcp140.dll is not shown correctly in exeinfo. <br>
I also found two API may related to my program as I use the file, but I didn’t find the place where directly call those two function in the definition of the function I called:<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/file.png)<br>
## Step 3 Packing and unpacking<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/step3.png)<br><br>
`before pack`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/beforepack.PNG)<br><br>
`after pack`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/afterpack.PNG)<br><br>
`unpack`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/unpack.PNG)<br><br>
Discuss:<br>
Compress the file will loose the information on OriginalFirstThunk and change the name. Decompress can not recover the information at OriginalFirstThunk but can recover the name. Also, the unpack operation is unsuccessful which broken my binary code, I check the information in the Hex view, it is same as the original code, but it can’t run.<br>
## step 4<br>
ADD the feather code of one particular virus to the PE header, but it’s not working.....<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/featurecode.png)<br><br>
`packed by Aspack:`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/aspack.png)<br><br>
`Packed by UPX`<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/upx.png)<br><br>
`Change by VCprotect Virtualization tool (http://www.vcprotect.com):`<br>
hide the import table:<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/vcp.png)<br>
This tool also encrypted the Register and metamorphose the code.<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/vcp2.png)<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/vcp3.png)<br><br>
`Packed by VCprotect then packed by upx'<br>
![](https://github.com/lovethatcat/EECS-444-ComputerSecurity/raw/master/HW2Q1/Images/vcp4.png)<br><br>


