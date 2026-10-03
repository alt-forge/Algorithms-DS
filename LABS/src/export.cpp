#include <fstream>

#include "passport_gen.h"
#include "price_gen.h"
#include "rooms_nums_gen.h"
#include "date_gen.h"

#include "export.h"

void writer(std::ofstream& file, int count) {
    rooms_init();
    // Вывод в итоговый файл
    for (int i = 0; i < count; i++) {
        file << nextPassport() << ' ';
        file << nextDate() << ' ';

        file << nextPrice();
        file << ' ';

        bool first = true;
        file << '{';
        for (int room : nextRooms_nums()) {
            if (!first) file << ',';
            file << room;
            first = false;
        }
        file << '}';
        
        file << "\n";
    }
}
