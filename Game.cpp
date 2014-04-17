#include "Game.h"
#include "SceneSys.h"
#include "GameMenu.h"
#include "InputHandler.h"
#include "Lima.h"
#include "Shot.h"
#include "PistolShot.h"
#include "Bird.h"
int spawnSpeed = 3500;
vector<Shot*> shots;
Sprite p_sprite;
Sprite bird_sprite;
Game::Game(RenderWindow *window):SceneParent(window)
{
	spawnSpeed = 3500;
	_health = 100;
	points = 0;
	loadAssets();
	_window = window;
	spawnTimer = new gameTimer(1000.0f);

	View view1(FloatRect(100,100,100,100));


	bird_sprite.setTexture(*TextureHandler::getTexture("bird"));
	bird_sprite.setScale(0.1f,0.1f);
	p_sprite.setTexture(*TextureHandler::getTexture("shot"));
	p_sprite.setOrigin(42,48);
	p_sprite.setScale(0.5f,0.5f);
	_shotPlayer.setBuffer(_shotSound);

			sprite.setTexture(*TextureHandler::getTexture("tausta"));

					teksti.setFont(fontti);
	teksti.setString("FPS :");
	teksti.setColor(Color::Black);
	teksti.setPosition(850,0);

	w_manager = WeaponManager(&bullets);
		gui = GUI(*_window,&fontti,&w_manager);
	enemy_sprite.setTexture(*TextureHandler::getTexture("enemy"));
	enemy_sprite.scale(0.3f,0.3f);

	player_sprite.setTexture(player);
	player_sprite.scale(0.3f,0.3f);
	player_sprite.setPosition(750,300);
	player_object = PlayerObject(player_sprite,0.0f);
	Clock deltaClock;
	Clock secondClock;
	Time delta = deltaClock.restart();
	Time second = secondClock.restart();

}
void Game::loadAssets()
{
	//textures
	
/*	if(!hp_border_tex.loadFromFile("hp_border.png"))
	{
		cout<<"Error"<<endl;
	}*/

	/*if(!hp_fill_tex.loadFromFile("hp_fill.png"))
	{
		cout<<"Error"<<endl;
	}*/
	/*	if(!tex.loadFromFile("kuva.png"))
	{
	cout<< "Error"<<endl;
	}*/
		/*if(!enemy.loadFromFile("image1.png"))
	{
	cout<< "Error"<<endl;
	}*/
		if(!player.loadFromFile("player.png"))
	{
	cout<< "Error"<<endl;
	}

		//fonts
	if(!fontti.loadFromFile("Arial.ttf"))
	{
		cout<<"Error loading font"<<endl;
	}
	//music
	if(!_shotSound.loadFromFile("shot.wav"))
	{
		cout<<"Error loading shot music"<<endl;
	}
}

Game::~Game(void)
{
	//_health = 100;
	cout<<"game poistettu"<<endl;
		it = viholliset.begin();
	while(it != viholliset.end())
	{
		delete (*it);
		 it = viholliset.erase(it);
		
	}
	vector<Shot*>::iterator s_it = shots.begin();
	while (s_it != shots.end())
	{
		delete (*s_it);
		s_it = shots.erase(s_it);
	}
	delete spawnTimer;
	//delete _window;
}
void Game::Update(float dt)
{
	w_manager.Update(dt);
	if(Keyboard::isKeyPressed(Keyboard::M))
	{
		openMenu();
		return;
	}
	else if(_health <= 0)
	{
		openMenu();
		return;
	}
		Update(dt,mousePos.y);
			checkEnemyHit(mousePos);
			if(spawnTimer->Update(dt))
		{
			createEnemy();
			spawnTimer->setDelay(rand() % spawnSpeed);
			if(spawnSpeed > 400)
			spawnSpeed*= 0.99f;
		}
			int frames = (1/dt);
		ostringstream buffer;
 buffer << frames;
string str = buffer.str();

		teksti.setString("FPS : " + str);

			// cout<<dt<<endl;
		 mousePos=  Mouse::getPosition(*_window);
}
void Game::checkEnemyDamage()
{
	for(int i = 0u; i < viholliset.size();i++)
	{
		if(viholliset.at(i)->canAttack())
			reduceHealth(viholliset.at(i)->getDamage());
	}
}
void Game::updateShots(float dt)
{
	vector<Shot*>::iterator s_it = shots.begin();
	while(s_it != shots.end())
	{
		
		if((*s_it)->playedOnce())
		{
			delete (*s_it);
			s_it = shots.erase(s_it);
			cout<<"Deleted"<<endl;
		}
		else
		{
			(*s_it)->Update(dt);
			s_it++;
		}
	}
}
void Game::Update(float dt,int mouseY)
{
	updateShots(dt);
	checkEnemyDamage();
	updateEnemies(dt);
	player_object.Update(dt,mouseY);
	updateBullets(dt);
	gui.Update(_health,dt);
}
void Game::checkEnemyHit(Vector2i mpos)
{
	//if(Mouse::isButtonPressed(Mouse::Left) && !LeftMouseDown)
	if(InputHandler::leftMouseStartedPressing())
	{
		//_shotPlayer.play();
		p_sprite.setPosition(mpos.x,mpos.y);
			shots.push_back(new PistolShot(p_sprite));
			w_manager.handleShot();
	for(int i = 0; i< viholliset.size();i++)
	{
		FloatRect collision =  viholliset.at(i)->getSprite().getGlobalBounds();
		if(collision.contains(mpos.x,mpos.y))
		{
			cout<<"Osuit viholliseen!"<<endl;
			cout<<++points<<endl;
			cout<<w_manager.getWeaponDamage()<<" weapon dmg"<<endl;
			viholliset.at(i)->loseHealth(w_manager.getWeaponDamage());
			return;
		}
	}
	cout<<"Ohi meni"<<endl;
	}
	
	
}
void Game::Draw()
{
		//window.setView(view1);
		_window->clear(Color(255,255,255));
	

		//Drawing stuff
				_window->draw(sprite);
				
		_window->draw(teksti);
		_window->draw(player_object.getSprite());
		drawEnemies();
				if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			for(int i = 0; i < 300;i++)
			{
			CircleShape shape2(100.f);
			_window->draw(shape2);
			}
		}
				for(int i = 0; i < shots.size(); i++)
					_window->draw(shots.at(i)->getSprite());
					gui.Draw();
		_window->display();
}

void Game::createEnemy()
{
		//viholliset.push_back(new Enemy(100.0f,80.0f,640,enemy_sprite,243,284,6,200.0f));
		//viholliset.push_back(new Enemy(100.0f,80.0f,640,enemy_sprite,480,480,12,35.0f));
	viholliset.push_back(new Lima(enemy_sprite));
	viholliset.push_back(new Bird(bird_sprite));
}
void Game::drawEnemies()
{
	for(int i = 0; i < viholliset.size();i++)
	{
		_window->draw(viholliset.at(i)->getSprite());
	}
}
void Game::updateEnemies(float dT)
{
	it = viholliset.begin();
	while(it != viholliset.end())
	{
		(*it)->Update(dT);
		if((*it)->isDead)
		{
			it = viholliset.erase(it);
		}
		else
			it++;

	}/*
		for(it = viholliset.begin(); it != viholliset.end();it++)
	{
		(*it)->Update(dT);
		if((*it)->isDead)
		{
			it =viholliset.erase(it);
			//it--;
		}
	}*/
}
void Game::updateBullets(float dt)
{
	for(int i = 0; i < bullets.size();i++)
	{
		bullets.at(i).Update(dt);
	}
}
void Game::openMenu()
{
	SceneSys::ChangeScene(new GameMenu(_window));
}
void Game::reduceHealth(int amount)
{
	_health -= amount;
	if(_health <= 0)
	{
		cout<<"Kuolit"<<endl;
	}
}