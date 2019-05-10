# Simon and Speck
Simon and Speck are lightweight block ciphers publicly released by the National Security Agency in June 2013. Speck has been optimized for software implementations, and Simon has been optimized for hardware implementations. 

![Speck Cipher](speck_cipher.png)
## Installation and Test
<ol>
	<li>Make all files</li>
		<ol>
			<li>make</li>
		</ol>
	<li>(Optional) create a random keyfile of 256 bits</li>
		<ol>
		<li>head /dev/urandom | tr -dc A-Za-z0-9 | head -c256 > keyfile</li>
		</ol>
	<li>Test Simon or Speck encryption/decryption
		<ol>
			<li>Test the Simon cipher: 256-bit key, 128-bit blocks, electronic code book mode, encrypt, keyfile, plaintext input, ciphertext output</li>
			<li>./user simon_256_128 ECB -e keyfile input output</li>
		</ol>
		<ol>
			<li>Test the Simon cipher: 256-bit key, 128-bit blocks, electronic code book mode, decrypt, keyfile, plaintext input, ciphertext output</li>
			<li>./user simon_256_128 ECB -d keyfile input output</li>
		</ol>
		<ol>
			<li>Test the Speck cipher: 256-bit key, 128-bit blocks, electronic code book mode, encrypt, keyfile, plaintext input, ciphertext output</li>
			<li>./user speck_256_128 ECB -e keyfile input output</li>
		</ol>
		<ol>
			<li>Test the Speck cipher: 256-bit key, 128-bit blocks, electronic code book mode, decrypt, keyfile, plaintext input, ciphertext output</li>
			<li>./user speck_256_128 ECB -d keyfile input output</li>
		</ol>
</ol>



 



