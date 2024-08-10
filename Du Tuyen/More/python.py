import random
import string
import hashlib

def generate_random_password(length: int = 12) -> str:
    # Define the character set: numbers and letters (both uppercase and lowercase)
    characters = string.ascii_letters + string.digits
    
    # Generate a random password from the character set
    random_password = ''.join(random.choice(characters) for _ in range(length))
    
    return random_password

# def generate_password_hash(password: str) -> str:
#     # Create a hash using SHA-256 algorithm
#     hash_object = hashlib.sha256(password.encode('utf-8'))
    
#     # Convert the hash to a hexadecimal string
#     password_hash = hash_object.hexdigest()
    
#     return password_hash

# Example usage
if __name__ == "__main__":
    
    # password_hash = generate_password_hash(password)
    for i in range(2, 23):
        print(generate_random_password())
    # print(f"Generated password hash: {password_hash}")
