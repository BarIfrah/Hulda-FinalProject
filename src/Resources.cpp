#include "Resources.h"
#include "Macros.h"
#include <exception>
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
    this->setNumOfSprites();
    m_font.loadFromFile("CooperBlackStd.otf");
}
//============================================================================
Resources& Resources::instance() {
    static Resources inst;
    return(inst);
}
//============================== gets section ================================
//============================================================================
const sf::Texture& Resources::getBackground() {
    return (*this->m_texture.find(MENU_BACKGROUND)->second);
}
//============================================================================
const sf::Texture& Resources::getTexture(int textureKey)const {
    return (*this->m_texture.find(textureKey)->second);
}
////============================================================================
const sf::Font& Resources::getFont() const{
    return m_font;
}
//============================================================================
int Resources::getNumOfSprites(int key)const {
    return (this->m_NumOfSprites.find(key)->second);
}
//============================== sets section ================================
void Resources::setBackgrounds() {
    std::unique_ptr<sf::Texture> texturesCreator;
    //adding game's backgrounds path

    texturesCreator = std::make_unique<sf::Texture>();

    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (MENU_BACKGROUND, std::move(texturesCreator)));

    if (!m_texture[MENU_BACKGROUND]->loadFromFile(MENU_BACKGROUND_PATH))
//        throw std::exception("Can't load background");
        throw std::exception();
        
    //------------------------------------------------------------------------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (MAIN_MENU_BACKGROUND, std::move(texturesCreator)));
    this->m_texture[MAIN_MENU_BACKGROUND]->loadFromFile(MAIN_MENU_BACKGROUND_PATH);
    //-----------------------------------------------------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (MENU, std::move(texturesCreator)));
    this->m_texture[MENU]->loadFromFile(MENU_PATH);
    //------------------------------------------------------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (HIGHMENU, std::move(texturesCreator)));
    this->m_texture[HIGHMENU]->loadFromFile(HIGHMENU_PATH);
    //--------------------------------------------------------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (HELPMENU, std::move(texturesCreator)));
    this->m_texture[HELPMENU]->loadFromFile(HELPMENU_PATH);
    //---------------------------------------------------------------
    //-------
     //------------------------------------------------------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (BACK_KEY, std::move(texturesCreator)));
    this->m_texture[BACK_KEY]->loadFromFile(BACK);
    //-------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (HI_SCORE_KEY, std::move(texturesCreator)));
    this->m_texture[HI_SCORE_KEY]->loadFromFile(HI_SCORE);
    //-------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (INFO_KEY, std::move(texturesCreator)));
    this->m_texture[INFO_KEY]->loadFromFile(INFO);
    //---------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (NEW_GAME_KEY, std::move(texturesCreator)));
    this->m_texture[NEW_GAME_KEY]->loadFromFile(NEW_GAME);
    //--------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (LIFE_T, std::move(texturesCreator)));
    this->m_texture[LIFE_T]->loadFromFile(LIFE_T_PATH);
    //--------
    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr <sf::Texture>>
        (EXIT_KEY, std::move(texturesCreator)));
    this->m_texture[EXIT_KEY]->loadFromFile(EXIT);


    //---------------------------------------------------------------
    //---------





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

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (ADANIT_KAHOL_T, std::move(texturesCreator)));
    this->m_texture[ADANIT_KAHOL_T]->loadFromFile(ADANIT_KAHOL_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (ADANIT_SAGOL_T, std::move(texturesCreator)));
    this->m_texture[ADANIT_SAGOL_T]->loadFromFile(ADANIT_SAGOL_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (ADANIT_KATOM_T, std::move(texturesCreator)));
    this->m_texture[ADANIT_KATOM_T]->loadFromFile(ADANIT_KATOM_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (DYNAMIC_FLOOR_T, std::move(texturesCreator)));
    this->m_texture[DYNAMIC_FLOOR_T]->loadFromFile(DYNAMIC_FLOOR_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (TRASH_BLUE_T, std::move(texturesCreator)));
    this->m_texture[TRASH_BLUE_T]->loadFromFile(TRASH_BLUE_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (TRASH_RED_T, std::move(texturesCreator)));
    this->m_texture[TRASH_RED_T]->loadFromFile(TRASH_RED_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (BURGER_T, std::move(texturesCreator)));
    this->m_texture[BURGER_T]->loadFromFile(BURGER_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (APPLE_T, std::move(texturesCreator)));
    this->m_texture[APPLE_T]->loadFromFile(APPLE_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (BANANA_T, std::move(texturesCreator)));
    this->m_texture[BANANA_T]->loadFromFile(BANANA_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (WATERMELON_T, std::move(texturesCreator)));
    this->m_texture[WATERMELON_T]->loadFromFile(WATERMELON_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (PIZZA_T, std::move(texturesCreator)));
    this->m_texture[PIZZA_T]->loadFromFile(PIZZA_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
                                   (EXTERMINATOR_T, std::move(texturesCreator)));
    this->m_texture[EXTERMINATOR_T]->loadFromFile(EXTERMINATOR_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (SCOOTER_T, std::move(texturesCreator)));
    this->m_texture[SCOOTER_T]->loadFromFile(SCOOTER_PATH);

    texturesCreator = std::make_unique<sf::Texture>();
    this->m_texture.insert(std::pair<int, std::unique_ptr<sf::Texture>>
        (PORTAL_TRASH_T, std::move(texturesCreator)));
    this->m_texture[PORTAL_TRASH_T]->loadFromFile(PORTAL_TRASH_PATH);
}
//============================================================================
void Resources::setNumOfSprites() {
    this->m_NumOfSprites.insert(std::pair<int, int>(IDLE, NUM_OF_IDLE_SPRITE));
    this->m_NumOfSprites.insert(std::pair<int, int>(RUN, NUM_OF_RUNNING_SPRITE));
    this->m_NumOfSprites.insert(std::pair<int, int>(JUMP, NUM_OF_JUMP_SPRITE));
///    this->m_NumOfSprites.insert(std::pair<int, int>(FALL, NUM_OF_FALL_SPRITE));
    this->m_NumOfSprites.insert(std::pair<int, int>(DIE, NUM_OF_DIE_SPRITE));
}
