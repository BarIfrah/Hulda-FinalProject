#include "Resources.h"
#include "Macros.h"
//==================== Constructors & destructors section ====================
Resources::Resources()
//m_music()
{
    this->m_texture.clear();
    //this->m_soundBuffers.clear();
    //this->m_music.setVolume(MUSIC_VOLUME);
    this->setBackgrounds();
    //    this->setLogos();
    this->setObjects();
    //this->setSounds();
}
//============================================================================
Resources& Resources::instance() {
    static Resources inst;
    return(inst);
}
//============================== gets section ================================
//============================================================================
const sf::Texture& Resources::getBackground(int textureKey) {
    //    if(textureKey != this->m_backgroundLevelState){
    //        switch(textureKey){
    //            case 1:
    this->m_texture[MENU_BACKGROUND]->
        loadFromFile(MENU_BACKGROUND_PATH);
    //                break;
    //            case 2:
    //                this->m_texture[LEVEL_BACKGROUND]->
    //                        loadFromFile(LEVEL2_BACKGROUND_PATH);
    //                break;
    //            case 3:
    //                this->m_texture[LEVEL_BACKGROUND]->
    //                        loadFromFile(LEVEL3_BACKGROUND_PATH);
    //                break;
    //            case 4:
    //                this->m_texture[LEVEL_BACKGROUND]->
    //                        loadFromFile(LEVEL4_BACKGROUND_PATH);
    //                break;
    //        }
    //        this->m_backgroundLevelState = textureKey;
    //    }
    return (*this->m_texture.find(MENU_BACKGROUND)->second);
}
//============================================================================
const sf::Texture& Resources::getTexture(int textureKey)const {
    return (*this->m_texture.find(textureKey)->second);
}
////============================================================================
//const sf::SoundBuffer& Resources::getSound(int soundKey) const{
//    return(*this->m_soundBuffers.find(soundKey)->second);
//}
////============================================================================
//const sf::Font& Resources::getFont(int fontKey) const{
//    return(*this->m_font.find(fontKey)->second);
//}

//============================== sets section ================================
void Resources::setBackgrounds() {
    std::unique_ptr<sf::Texture> texturesCreator;
    //adding game's backgrounds path
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (MENU_BACKGROUND, std::move(texturesCreator)));
    this->m_texture[MENU_BACKGROUND]->loadFromFile(MENU_BACKGROUND_PATH);
    //------------------------------------------------------------------------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (GAME_STATE, std::move(texturesCreator)));
    this->m_texture[GAME_STATE]->loadFromFile(GAME_STATE_PATH);
    //------------------------------------------------------------------------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (LEVEL_BACKGROUND, std::move(texturesCreator)));
    //adding levels background path
}
//============================================================================
void Resources::setObjects() {
    std::unique_ptr<sf::Texture> texturesCreator;

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (PLAYER_T, std::move(texturesCreator)));
    this->m_texture[PLAYER_T]->loadFromFile(PLAYER_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (ROAD_T, std::move(texturesCreator)));
    this->m_texture[ROAD_T]->loadFromFile(ROAD_PATH);
}