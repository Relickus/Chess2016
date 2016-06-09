#ifndef CCONTROLLER_H
#define	CCONTROLLER_H

#include "COLOR.h"
#include "CGameSession.h"
class CAbstractMenuScreen;

/**
 * 
 * Třída obstarávající propojení ostatních tříd
 */
class CController {
public:
    CController();
    /**
     * @brief Smaže spojový seznam menu obrazovek
     */
    virtual ~CController();
    /**
     * @brief Zavolá zobrazení aktuálního menu
     */
    void showMenus();
    /**
     * @brief Zavolá inicializaci hry
     */
    void startGame();
        /**
     * @brief Zavolá ukončení hry a uvolnění dyn. struktur
     */
    void endGame();
     /**
     * @brief Vrátí referenci na instanci hry
     */
    CGameSession & getGameSess();
        /**
     * @brief Hlavní herní smyčka
     */
    void gameLoop();
     /**
     * @brief Zavolá inicializaci serveru
     */
    int startServer();
    
private:
    /**
     * @brief Vymaže menu obrazovky
     */
    void deleteMenus();

    CAbstractMenuScreen * menu;
    CGameSession game;
    //CGUI gui;
};

#endif	/* CCONTROLLER_H */

