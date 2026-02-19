**Reads in a binary file, decoding its contents, and printing the decoded text onto the screen.**
Instructions; have all the files in the same destination (msg0.enc, msg0.plain, msg0.key, lab5.cpp)
The dkey for msg0.enc is B and the nkey is 127.

**To run:**
./lab5 msg0.enc B 127

this outputs the correct decrpyted code.
however If you input the wrong dkey or nkey such as  ./lab5 msg0.enc C 127  
then the code wont be decrpyted correctly.


**More background:**
The binary files are encrypted by using two keys: a dkey (data key) and an nkey (index key). These two keys must match what was used to encrypt the files in order to decrypt the data.
The data key is exactly 8 bits and the index key is exactly 32 bits, and they will be supplied as the second command line argument and third command line argument, respectively. The first command line argument is the name of the encrypted file. 

The encryption scheme encrypts the data, byte-by-byte, then it shuffles where the bytes are located within the file. This means to decrypt the file, you must decrypt the data using the dkey and then locate the next block to decrypt using the nkey.
Each block in the encrypted file is exactly 8 bytes. The first byte is the actual data and the last 4 bytes is the index that data belongs to. The middle three bytes are called "padding" and are not used. You must ignore these bytes.

When you read the first block, you will get an encrypted data byte and an encrypted index (4 bytes). To decrypt the data byte, you must XOR the encrypted data byte with the dkey. To decrypt the index, you must XOR the encrypted index with the nkey.
Now, you should have a decrypted data byte and a decrypted index. For example, say the decrypted byte is 'B' and the decrypted index is 4. This means that all_data[4] = 'B'. In other words, the index describes a 0-based index into a full size data array. For a properly encrypted file, all indices will be represented somewhere within the file. However, you must still error check to ensure decryption is successful. If something does not decrypt within sane bounds, you must let the user know.

You will continue to decrypt block-by-block until all blocks have been decrypted. Afterward, you will have an array of characters, which contains the data you need to print to the screen.
