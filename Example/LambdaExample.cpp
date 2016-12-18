#include <iostream>
#include <vector>
#include <string>

enum class Arrow : unsigned int { SAME = 0, UP, DOWN };
using UiSomeContentsArrowVec = std::vector<std::pair<std::string, Arrow>>;
void SomeFunc(const int&, UiSomeContentsArrowVec&);

void main()
{
    UiSomeContentsArrowVec uiArrowVec;
    uiArrowVec.reserve(3);

    unsigned int updatedPoint = 20;
    SomeFunc(updatedPoint, uiArrowVec);

    for (auto data : uiArrowVec)
    {
        std::cout << data.first << " = " << static_cast<unsigned int>(data.second) << std::endl;
    }

    return;
}

void SomeFunc(const int& updatedPoint, UiSomeContentsArrowVec& uiArrowVec)
{
    // get prev point data
    const unsigned int somePoint = 10;
    const unsigned int otherPoint = 20;
    const unsigned int theOtherPoint = 30;

    auto someArrow = Arrow::SAME;
    auto otherArrow = Arrow::SAME;
    auto theOtherArrow = Arrow::SAME;

    // TODO:
    // compare previous point and updated point
    auto GetArrow = [](const unsigned int& prev, const unsigned int& cur) -> Arrow
    {
        return prev == cur ? Arrow::SAME : (prev > cur ? Arrow::DOWN : Arrow::UP);
    };
    
    someArrow = GetArrow(somePoint, updatedPoint);
    otherArrow = GetArrow(otherPoint, updatedPoint);
    theOtherArrow = GetArrow(theOtherPoint, updatedPoint);

    // input data at ui arrow vector
    uiArrowVec.clear();
    uiArrowVec.push_back(std::make_pair("someArrow", someArrow));
    uiArrowVec.push_back(std::make_pair("otherArrow", otherArrow));
    uiArrowVec.push_back(std::make_pair("theOtherArrow", theOtherArrow));

    return;
}