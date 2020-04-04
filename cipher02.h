/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Tyler Starr"; }
   virtual std::string getCipherName()  { return "TEA (Tiny Encryption Algorithm)"; }
   virtual std::string getEncryptAuth() { return "Tyler Starr"; }
   virtual std::string getDecryptAuth() { return "Tyler Starr"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://citeseer.ist.psu.edu/viewdoc/download;jsessionid=C08E8409ADF484095568965A1EBF3E5E?doi=10.1.1.45.281&rep=rep1&type=pdf");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   long v[2] = plainText\n";
      str += "   long k[2] = password\n";
      str += "   y = v[0]\n";
      str += "   z = v[1]\n";
      str += "   sum = 0\n";
      str += "   delta = 0x9e3779b9\n\n";

      str += "   FOR n from 32 to 0:\n";
      str += "      sum = sum + delta\n";
      str += "      y = y +\n";
      str += "         ((z << 4) + k[0]) XOR\n";
      str += "         (z + sum) XOR\n";
      str += "         ((z >> 5) + k[1])\n";
      str += "      z = z +\n";
      str += "         ((y << 4) + k[2]) XOR\n";
      str += "         (y + sum) XOR\n";
      str += "         ((y >> 5) + k[3])\n";
      str += "   END FOR\n";
      str += "   v[0] = y\n";
      str += "   v[1] = z\n";
      str += "   cipherText = v\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str +=  "decrypt(cipherText, password)\n";
      str += "   long v[2] = cipherText\n";
      str += "   long k[2] = password\n";
      str += "   y = v[0]\n";
      str += "   z = v[1]\n";
      str += "   delta = 0x9e3779b9\n";
      str += "   sum = delta << 5\n\n";

      str += "   FOR n from 32 to 0:\n";
      str += "      z = z -\n";
      str += "         ((y << 4) + k[2]) XOR\n";
      str += "         (y + sum) XOR\n";
      str += "         ((y >> 5) + k[3])\n";
      str += "      y = y -\n";
      str += "         ((z << 4) + k[0]) XOR\n";
      str += "         (z + sum) XOR\n";
      str += "         ((z >> 5) + k[1])\n";
      str += "      sum = sum - delta\n";
      str += "   END FOR\n";
      str += "   v[0] = y\n";
      str += "   v[1] = z\n";
      str += "   plainText = v\n";
      str += "   RETURN plainText\n";

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

      // This algorithm can cause stack smashing if a
      // block is less than 8 bytes in length
      while (cipherText.size() % 8 != 0)
         cipherText += ' ';

      long* v = (long*)(cipherText.c_str());
      long* k = (long*)(password.c_str());

      // Each block is 8 bytes in size.
      int numIterations = cipherText.size() / 8;
      while (numIterations --> 0)
         encrypt_8(v++, k);

      return cipherText;
   }

   /**********************************************************
    * ENCRYPT_8
    * Encrypts 8 bytes of v using k as the key
    **********************************************************/
   void encrypt_8(long* v, long* k)
   {
      unsigned long y = v[0];
      unsigned long z = v[1];
      unsigned long sum = 0;
      unsigned long delta = 0x9e3779b9;
      unsigned long n = 32;

      while (n --> 0)
      {
         sum += delta;
         y += (z << 4) + k[0] ^ z + sum ^ (z >> 5) + k[1];
         z += (y << 4) + k[2] ^ y + sum ^ (y >> 5) + k[3];
      }
      
      v[0] = y;
      v[1] = z;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;

      long* v = (long*)(plainText.c_str());
      long* k = (long*)(password.c_str());

      // Apply the decryption to the same 8-byte size blocks
      int numIterations = plainText.size() / 8;
      while (numIterations --> 0)
         decrypt_8(v++, k);

      return plainText;
   }

   /**********************************************************
    * DECRYPT_8
    * Decrypts 8 bytes of v using k as the key
    **********************************************************/
   void decrypt_8(long* v, long* k)
   {
      unsigned long n = 32;
      unsigned long sum;
      unsigned long y = v[0];
      unsigned long z = v[1];
      unsigned long delta = 0x9e3779b9;

      sum = delta << 5;

      while (n --> 0)
      {
         z -= (y << 4) + k[2] ^ y + sum ^ (y >> 5) + k[3];
         y -= (z << 4) + k[0] ^ z + sum ^ (z >> 5) + k[1];
         sum -= delta;
      }

      v[0] = y;
      v[1] = z;
   }
};

#endif // CIPHER02_H
