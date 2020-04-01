/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#include <algorithm>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Ben Smith"; }
   virtual std::string getCipherName()  { return "cipher name"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("citation");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "insert the encryption pseudocode\n";

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

      return str;
   }


   std::string keyRandomizeAlgorithm(std::string & streamInput, 
                                     std::string password)
   {
      for (int h=0; h < 255; h++)
          streamInput[h] = h;

      int j =0;
      char tempString;
      for (int i=0; i < 255; i++)
      {
        j = (j+ streamInput[i] + password[i % password.size()] 
        ) % 256;
        std::swap(streamInput[i], streamInput[j]);

      }

   }

   char pseudoRandomGeneration(std::string streamInput, 
                              int & j,
                              int & i)
   {

      int sizeOfStream = streamInput.size();

      while(1)
      {
        i = (i+1) % 256;
        j = (j + streamInput[i]) % 256;
        std::swap(streamInput[i], streamInput[j]);

        int t = (streamInput[i] + streamInput[j]) % 256;
        return streamInput[t];
      }
   }
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      
      
      std::string cipherText;
      // TODO - Add your code here
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER01_H
