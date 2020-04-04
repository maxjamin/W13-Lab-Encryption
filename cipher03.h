/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Bretton Steiner"; }
   virtual std::string getCipherName()  { return "Blowfish"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s = "Salma, et al. \"Enhancing Cloud Data Security Using Hybrid of Advanced Encryption Standard and Blowfish Encryption Algorithms.\"\n";
      s += "\t2018 2nd East Indonesia Conference on Computer and Information Technology (EIConCIT), Computer and Information Technology (EIConCIT),\n";
      s += "\t2018 2nd East Indonesia Conference On, Nov. 2018, pp. 18–23. EBSCOhost, doi:10.1109/EIConCIT.2018.8878629.\n";
      s += "\tRetrieved: https://ieeexplore-ieee-org.byui.idm.oclc.org/stamp/stamp.jsp?tp=&arnumber=8878629 \n\n";

      s += "Chauhan, Adviti, and Jyoti Gupta. \"A Novel Technique of Cloud Security Based on Hybrid Encryption by Blowfish and MD5.\"\n";
      s += "\t2017 4th International Conference on Signal Processing, Computing and Control (ISPCC), Signal Processing, Computing and Control (ISPCC),\n";
      s += "\t2017 4th International Conference On, Sept. 2017, pp. 349–355. EBSCOhost, doi:10.1109/ISPCC.2017.8269702.\n";
      s += "\tRetrieved: https://ieeexplore-ieee-org.byui.idm.oclc.org/stamp/stamp.jsp?tp=&arnumber=8269702 \n\n";

      s += "Abd El-Sadek, A. A., et al. \"Speech Encryption Applying a Modified Blowfish Algorithm.\"\n";
      s += "\t2014 International Conference on Engineering and Technology (ICET), Engineering and Technology (ICET),\n";
      s += "\t2014 International Conference On, Apr. 2014, pp. 1–6. EBSCOhost, doi:10.1109/ICEngTechnol.2014.7016764.\n";
      s += "\tRetrieved: https://ieeexplore-ieee-org.byui.idm.oclc.org/stamp/stamp.jsp?tp=&arnumber=7016764 \n\n";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // Note: plainText, cipherText, and password are all 32-bit strings
      // Another Note: decrypt is exactly the same as encrypt except it runs through P[] backwards

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   DO initialize(password)\n";
      str += "   SET L <- first half of plainText\n";
      str += "   SET R <- second half of plainText\n";
      str += "   FOR i = 0 to 15\n";
      str += "      SET L <- L XOR P[i]\n";
      str += "      SET R <- f(L) XOR R\n";
      str += "      DO swap(L, R)\n";
      str += "   DO swap(L, R)\n";
      str += "   SET R <- R XOR P[16]\n";
      str += "   SET L <- L XOR P[17]\n";
      str += "   SET cipherText <- L + R\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   DO initialize(password)\n";
      str += "   SET L <- first half of cipherText\n";
      str += "   SET R <- second half of cipherText\n";
      str += "   FOR i = 17 to 2\n";
      str += "      SET L <- L XOR P[i]\n";
      str += "      SET R <- f(L) XOR R\n";
      str += "      DO swap(L, R)\n";
      str += "   DO swap(L, R)\n";
      str += "   SET R <- R XOR P[1]\n";
      str += "   SET L <- L XOR P[0]\n";
      str += "   SET plainText <- L + R\n";
      str += "   RETURN plainText\n\n";

      // The "f" function pseudocode
      str += "f(x)\n";
      str += "   Work-In-Progress\n\n";

      // The initialize pseudocode
      str += "initialize(password)\n";
      str += "   Work-In-Progress\n\n";

      // The swap pseudocode
      str += "swap(L, R)\n";
      str += "   SET temp <- L\n";
      str += "   SET L <- R\n";
      str += "   SET R <- temp\n";
      str += "   RETURN\n\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
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

private:

   /**********************************************************
    * INITIALIZE
    * Takes the password and initializes P.
    **********************************************************/
   void initialize(string password)
   {
      return;
   }

   /**********************************************************
    * F
    * Does some weird shenanagens that I don't understand.
    **********************************************************/
   string f(string X)
   {
      return X;
   }

   /**********************************************************
    * SWAP
    * Swaps the values of the two variables
    **********************************************************/
   void swap(string & L, string & R)
   {
      string temp = L;
      L = R;
      R = temp;
      return;
   }

   string P[18];
};

#endif // CIPHER03_H
