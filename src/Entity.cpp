#include "Entity.hpp"

Entity::Entity(b2World *World, int x, int y, string texture, Game *game)
{
    this->game = game;


    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
    BodyDef.type = b2_dynamicBody;
    Body = World->CreateBody(&BodyDef);

    b2PolygonShape Shape;

    if(!texture.compare("box"))
    {
        Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);
    }
    else
    {
        Shape.SetAsBox((80.f/2.5) / SCALE, (145.f/2.5)/SCALE);
        /*
        b2Vec2 vertices[7];

        vertices[0].Set(0.f, 0.f);
        vertices[1].Set(80.f / SCALE, 0.f);
        vertices[2].Set(80.f / SCALE, 145.f/SCALE);
        vertices[3].Set(0.f, 145.f/SCALE);
   /*
        vertices[0].Set((43.f)/SCALE,   (6.f)/SCALE);
        vertices[1].Set((25.f)/SCALE,   (34.f)/SCALE);
        vertices[2].Set((25.f)/SCALE,  (80.f)/SCALE);
        vertices[3].Set(( 5.f)/SCALE, (128.f)/SCALE);
        vertices[4].Set((82.f)/SCALE, (128.f)/SCALE);
        vertices[5].Set((61.f)/SCALE,  (80.f)/SCALE);
        vertices[6].Set((61.f)/SCALE,  (34.f)/SCALE);

        Shape.Set(vertices, 4);
        */
    }

    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.1f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;

    Body->CreateFixture(&FixtureDef);
    sprite.setTexture(this->game->textureManager.getRef(texture));
    sprite.setOrigin(this->game->textureManager.getRef(texture).getSize().x / 2.f,
                     this->game->textureManager.getRef(texture).getSize().y / 2.f);

}

void Entity::draw()
{
    sprite.setPosition(SCALE * this->Body->GetPosition().x, SCALE * this->Body->GetPosition().y);
    sprite.setRotation(this->Body->GetAngle() * (180)/b2_pi);

    this->game->window.draw(sprite);
}

Entity::~Entity()
{
    //dtor
}
