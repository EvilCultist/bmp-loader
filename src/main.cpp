#include <fstream>
#include <iostream>

struct Color {
  char r;
  char g;
  char b;
  char a;
};

int main() {
  std::string filePath = "images/mask.bmp";
  filePath = "images/testfile.bmp";
  std::ifstream file(filePath, std::ios::binary);
  std::uint8_t *fileHeader = nullptr;
  std::uint8_t *dibHeader = nullptr;
  char databuff[] = {'\0', '\0'};
  std::uint8_t *pixels = nullptr;
  char fileSize[12]; // = {0x00, 0x00, 0x00, 0x00};

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
  char headerSize[4];
  file.read(headerSize, sizeof(headerSize));
  char header[headerSize[0] * 20]; // = {0x00, 0x00, 0x00, 0x00};
  file.read(header, sizeof(header));
  int i = 1;
  for (auto val : header) {
    std::cout << (uint16_t)val << " ";
    if (i == 4) {
      std::cout << std::endl;
      i = 0;
    }
    i++;
  }
  file.seekg((uint16_t)fileSize[8] - (uint16_t)headerSize[0] - 4);
  std::cout << (uint16_t)fileSize[8] - (uint16_t)headerSize[0] - 4 << std::endl;
  char col[header[0] * header[4] * 4];
  file.read(col, sizeof(col));
  i = 0;
  for (int c = 0; c < header[4]; c++) {
    for (int r = 0; r < header[0]; r++) {
      int printval = ((uint16_t)col[i + 1]) / 10000;
      if (printval == 0) {
        std::cout << " "
                  << " ";
      } else {
        std::cout << "◼️"
                  << " ";
      }
      i += 4;
    }
    std::cout << std::endl;
  }
  // for( auto val : col){
  //     std::cout << val << " ";
  // }
  // Color data[header[0]][header[4]];
  // for (int datain = 0; datain < header[4]; datain++) {
  //   for (auto val : data[datain]) {
  //     file.read(&val.r, sizeof(char));
  //     file.read(&val.g, sizeof(char));
  //     file.read(&val.b, sizeof(char));
  //     file.read(&val.a, sizeof(char));
  //     if (val.r > 100) {
  //       std::cout << "⬛";
  //     } else {
  //       std::cout << " ";
  //     }
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;
  // std::cout << "hello world" << std::endl;
}
