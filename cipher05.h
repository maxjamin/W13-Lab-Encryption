/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H 
#define CIPHER05_H

#define BLOCKSIZE 4

/********************************************************************
 * CLASS ChaCha20 ENCRYPTION
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "John Miller"; }
   virtual std::string getCipherName()  { return "ChaCha20"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s =  "Internet Research Task Force ChaCha20 and Poly1305 for IETF Protocols\n";
      s += "https://csrc.nist.gov/csrc/media/projects/cryptographic-standards-and\n";      s += "-guidelines/documents/aes-development/rijndael-ammended.pdf";
      return s;
   }
   
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode, referenced from the Protocal paper
      str  = "chacha20_encrypt(key, counter, nonce, plaintext)\n";
      str += "  for counter=1 upto ceil(len(plaintext) / 64)\n";
      str += "    key_stream = chacha20_block(key, counter, nonce)\n";
      str += "    block = plaintext[((counter-1)*64)..(counter*64-1)]\n";
      str += "    encrypted_message +=  block ^ key_stream\n";
      str += "  end loop\n";
      str += "  if ((len(plaintext) % 64) != 0)\n";
      str += "    key_stream = chacha20_block(key, counter, nonce)\n";
      str += "    block = plaintext[(counter*64)..len(plaintext)-1]\n";
      str += "    encrypted_message += (block^key_stream)[0..len(plaintext)%64]\n";
      str += "  end if\n";
      str += "  return encrypted_mesage\n";
      str += "  end\n";

      // The decrypt pseudocode
      str += "Due to how ChaCha is built, the encrypt function can also decrypt\n";

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
};

#endif // CIPHER05_H
