from PIL import Image
import pytesseract
 
text = pytesseract.image_to_string(Image.open(r'C:\Users\pengwang\Documents\VS Code\Python\spider\test.png'))
print(text)