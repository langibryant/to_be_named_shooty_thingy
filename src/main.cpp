#include <ge/ge>

namespace temp {
    class Template : public ge::State {
    public:
        void update(){}
        void render(){}
    };
}

GE_MAIN(temp::Template, 1920, 1080, "Template")