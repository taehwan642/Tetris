#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p = nullptr; } // p�� nullptr�� �ƴҶ� p�� delete �� p = nullptr ����