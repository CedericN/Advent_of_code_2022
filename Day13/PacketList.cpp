//
// Created by icas on 12/13/22.
//

#include "PacketList.h"

PacketList::PacketList(string &input, bool driverPack) {
//    cout << "input: " << input << endl;
    driverPackage = driverPack;
    list = true;
    while(!input.empty()){
        if(input.front() == '['){
            uint8_t counter = 1;
            uint64_t lastPos = 1;
            while(counter != 0){
                uint64_t posOpen = input.find('[', lastPos);
                uint64_t posClose = input.find(']', lastPos);
                counter += posClose < posOpen ? -1 : +1;
                lastPos = posClose < posOpen ? posClose + 1 : posOpen + 1;
            }
//            cout << "last Pos: " << lastPos << endl;
            string tmp = input.substr(1, lastPos - 2);
            containingLists.emplace_back(tmp);
            input = lastPos != input.size() ? input.substr(lastPos + 1) : "";
        }
        else{
            uint64_t pos = input.find(',');
            if(pos != string::npos){
                containingLists.emplace_back(stoi(input.substr(0, pos)));
                input = input.substr(pos + 1);
            }
            else{
                containingLists.emplace_back(stoi(input));
                input.clear();
            }
        }
    }
    item = 0;
}

PacketList::PacketList(const uint8_t item) {
    list = false;
    driverPackage = false;
    this->item = item;
}

PacketList::returnOperator PacketList::operator==(PacketList &obj) {
    if(list == obj.list){
        if(list){

//            cout << "comparing lists ";
//            printPacket();
//            cout << " and ";
//            obj.printPacket();
//            cout << endl;

            uint32_t size = containingLists.size() < obj.containingLists.size() ? containingLists.size() : obj.containingLists.size();
            for (uint32_t i = 0; i < size; ++i) {
                switch (containingLists.at(i) == obj.containingLists.at(i)) {
                    case less:
                        return less;
                    case greater:
                        return greater;
                    case equal:
                        break;
                }
            }
            if(containingLists.size() < obj.containingLists.size()){return less;}
            else if(containingLists.size() > obj.containingLists.size()){return greater;}
            else{return equal;}
        }
        else{
//            cout << "comparing items " << (int) item << " and " << (int) obj.item << endl;
            if(item < obj.item){return less;}
            else if(item > obj.item){return greater;}
            else{return equal;}
        }
    }
    else {

//        if(list){
//            cout << "comparing combination ";
//            printPacket();
//            cout << " and " << (int) obj.item << endl;
//        }
//        else{
//            cout << "comparing combination " << (int) item << " and ";
//            obj.printPacket();
//            cout << endl;
//        }

        uint32_t size = list ? containingLists.size() : obj.containingLists.size();
        if(size == 0){
            return list ? less : greater;
        }
        else{
            PacketList *tmpList = list ? this : &obj;
            uint8_t itemTMP = UINT8_MAX;
            while (itemTMP == UINT8_MAX){
                if(!tmpList->list){
                    itemTMP = tmpList->item;
                }
                else if(!tmpList->containingLists.empty()){
                    tmpList = &tmpList->containingLists.front();
                }
                else{
                    return list ? less : greater;
                }
            }
            uint8_t item1 = list ? itemTMP : item ;
            uint8_t item2 = obj.list ? itemTMP : obj.item ;
            if(item1 < item2){return less;}
            else if(item1 > item2){return greater;}
            else{
                return size == 1 ? equal : (list ? greater : less);
            }
        }
    }
}
