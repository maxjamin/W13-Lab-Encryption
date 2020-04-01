/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

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
      return std::string("citation: https://www.researchgate.net/publication/311424500_An_Overview_of_the_RC4_Algorithm, https://stepuptocrypt.blogspot.com/2019/02/symmetric-cryptography-rc4-algorithm.html\n ");
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
      str =  "Two parts of the algorithm\n",
              "Key-scheduling algorithm\n",
                "for i from 0 to 255\n"
                  "s[i] := 1\n",
              "endfor\n",
              "\n",
              "i, j :=0\n",
              "while(generatingOutput:\n",
                "i := (i + 1) mod 256\n",
                "j := (j + S[i]) mod 256\n",
                "swap values of S[i] and S[j]\n",
                "K := S[(S[i] + S[j]) mod 256]\n",
                "output K\n",
              "endwhile\n"
              ;

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

      return str;
   }

    int keyRandomizeAlgorithm(int *streamInput, 
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

   int pseudoRandomGeneration(int *streamInput, 
                              int & j,
                              int & i)
   {

      std::cout << "i is " << i << " j is " << j << "\n";
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
      int initalVector[256];

      keyRandomizeAlgorithm(initalVector, password);

      int i = 0;
      int j = 0;
      for(std::string::size_type h=0; h < plainText.size(); h++)
      {
        int k = pseudoRandomGeneration(initalVector, j, i);

        //convert plaintext to int
        int plain_as_int = (int)plainText[h];
        //std::cout << "plain_as_int " << plain_as_int << "\n";

        //XOR plaintext and k from keystream
        int output = k^plain_as_int;

        std::cout << "plainText: " << plainText[h] << " - k being " <<
        k << " Converted to " << output <<"\n";

        //add to cipherText
        cipherText.push_back((char)output);
        std::cout << "cipherText is " << cipherText[h] << " - ";
      }

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
