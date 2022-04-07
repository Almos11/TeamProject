#include "game_object.h"

struct GameObject;

struct GameObject {
    std::string namePlayer;
    std::unordered_map <std::string, std::shared_ptr<Component>> components;
    GameObject(std::string name, std::unordered_map <std::string, std::shared_ptr<Component>> newComponents) : namePlayer(
            std::move(name)), components(std::move(newComponents)) {
    }

    template<typename T>
    std::shared_ptr <T> getComponent(const std::string &componentName) {
        return std::dynamic_pointer_cast<T>(this->components[componentName]);
    }
};