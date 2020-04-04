/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <sstream> // for converting string to number + vice versa

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Bretton Steiner"; }
   virtual std::string getCipherName()  { return "Blowfish"; }
   virtual std::string getEncryptAuth() { return "Tyler Starr"; }
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
      str += "   SET h <- S[0][x >> 24]\n";
      str += "   SET h <- h + S[1][x >> 16 AND 0xff]\n";
      str += "   SET h <- h XOR S[2][x >> 8 AND 0xff]\n";
      str += "   SET h <- h + S[3][x AND 0xff]\n";
      str += "   RETURN h\n\n";

      // The initialize pseudocode
      str += "initialize(password)\n";
      str += "   Initialize P and S using hexadecimal words of pi\n";
      str += "   XOR each P with password, 32 bits at a time, repeating the use of password if needed\n";
      str += "   Do a bunch more stuff that is too complicated to write out in pseudocode in this time\n";
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
    * Encrypt using XOR and some global arrays (S and P)
    * derived from password
    * TODO: implement the initialize() function
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      int size = plainText.size();
      initialize((uint32_t)password.c_str());

      uint32_t L = ((uint32_t)plainText.c_str());
      uint32_t R = (L + sizeof(uint32_t) * (size / 2));

      for (int i = 0; i < 15; i++)
      {
         L ^= (uint32_t)P[i];
         R ^= f(L);
         swap(L, R);
      }

      swap(L, R);
      R ^= password[16];
      L ^= password[17];

      // https://www.cplusplus.com/articles/D9j2Nwbp/
      std::string cipherText = static_cast<std::ostringstream*>( &(std::ostringstream() << (L + R)) )->str();

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
   void initialize(uint32_t password)
   {
      // Initialize P and S-Boxes with pi? I couldn't find anyway to do this online. So this will not work.

      for (int i=0 ; i<18 ; ++i)
         P[i] ^= password; //Password for this code will always be 32 bit and thus used every round
      uint32_t L = 0, R = 0;
      for (int i=0 ; i<18 ; i+=2) {
         encrypt (L, R);
         P[i] = L; P[i+1] = R;
      }
      for (int i=0 ; i<4 ; ++i)
         for (int j=0 ; j<256; j+=2) {
            encrypt (L, R);
            S[i][j] = L; S[i][j+1] = R;
         }

      return;
   }

   /**********************************************************
    * F
    * Encrypts using the 4 S-boxes
    **********************************************************/
   uint32_t f(uint32_t x)
   {
      uint32_t h = S[0][x >> 24] + S[1][x >> 16 & 0xff];
      h = (h ^ S[2][x >> 8 & 0xff]) + S[3][x & 0xff];
      return h;
   }

   /**********************************************************
    * SWAP
    * Swaps the values of the two variables
    **********************************************************/
   void swap(uint32_t & L, uint32_t & R)
   {
      uint32_t temp = L;
      L = R;
      R = temp;
      return;
   }

   uint32_t P[18];
   uint32_t S[4][256];
};

#endif // CIPHER03_H
