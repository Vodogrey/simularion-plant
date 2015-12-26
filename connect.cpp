#include "connect.h"

Connect::Connect(QObject *parent) : QObject(parent)
{

}
//
// от этого скорее всего избавимся
//

//bool Connect::isAvailable(int stage)
//{
//    switch (stage)
//    {
//    case 0: if(emit getCount(0) >= 1 && emit getCount(1) >= 2) { //D3
//                setCount(0, -1);
//                setCount(1, -2);
//                return true;
//                  break;
//    }
//    case 1: if(emit getCount(0) >= 1 && emit getCount(1) >= 1 && emit getCount(2) >= 1) { //E4
//                setCount(0, -1);
//                setCount(1, -1);
//                setCount(2, -1);
//                return true;
//                  break;
//    }
//    case 2:  if(emit getCount(3) >= 1 && emit getCount(4) >= 1) {//check
//            return true;
//              break;
//    }
//    case 3: if(emit getCount(1) >= 1 && emit getCount(3) >= 1) { //F
//            setCount(1, 1);
//            setCount(3, 1);
//            return true;
//              break;
//    }
//    case 4: if(emit getCount(6) >= 1 && emit getCount(4) >= 1) { //G
//            setCount(6, 1);
//            setCount(4, 1);
//            return true;
//              break;
//        }
//    case 5: if(emit getCount(7) >= 1 && emit getCount(1) >= 1 && emit getCount(2) >= 2) { //end
//            setCount(7, 1);
//            setCount(1, 1);
//            setCount(2, 2);
//            return true;
//              break;
//        }

//    default: return false;
//    }

//}
