#ifndef SETTING_H_
#define SETTING_H_
#include <SFML/System/String.hpp>

class Setting
{
private:
    static Setting *pSetting;

    // 窗口配置
    int window_width;
    int window_height;
    sf::String window_title;
    int frame_limit;


    Setting()
    {
        pSetting = this;
        window_title = L"小朋友齐打交";
        window_width = 2400;
        window_height = 1500;
        frame_limit = 4;
    }

public:
    int getWindowWidth() const { return window_width; }
    int getWindowHeight() const { return window_height; }
    sf::String getWindowTitle() const { return window_title; }
    int getFrameLimit() const { return frame_limit; }

    void setWindowWidth(int width) { this->window_width = width; }
    void setWindowHeight(int height) { this->window_height = height; }
    void setWindowTitle(sf::String &title) { this->window_title = title; }
    void setFrameLimit(int limit) { this->frame_limit = limit; }

    ~Setting() = default;

    static Setting *getInstance() { return pSetting; }
};

#endif // SETTING_H_
