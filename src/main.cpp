#include <fstream>
#include <iostream>

int main() {
  std::string filePath = "images/mask.bmp";
  std::ifstream file(filePath, std::ios::binary);
  std::uint8_t *fileHeader = nullptr;
  std::uint8_t *dibHeader = nullptr;
  char databuff[] = {'\0', '\0'};
  std::uint8_t *pixels = nullptr;
  char fileSize[4]; // = {0x00, 0x00, 0x00, 0x00};

  if (!file) {
    std::cerr << "file not found" << std::endl;
    return -1;
  }
  file.read(databuff, sizeof(databuff));
  if (!(databuff[0] == 'B' && databuff[1] == 'M')) {
    std::cerr << "file not bmp" << std::endl;
  }
  file.read(fileSize, sizeof(fileSize));
  for (auto val : fileSize) {
    std::cout << (uint16_t)val << " ";
  }
  std::cout << std::endl;
  std::cout << "hello world" << std::endl;
}
