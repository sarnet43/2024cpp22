#include <SFML/Graphics.hpp>
#include <vector>

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;
constexpr float ballRadius = 10.f;
constexpr float ballVelocity = 8.f;
constexpr float paddleWidth = 60.f;
constexpr float paddleHeight = 20.f;
constexpr float paddleVelocity = 10.f;
constexpr int brickRows = 5;
constexpr int brickColumns = 10;
constexpr float brickWidth = 60.f;
constexpr float brickHeight = 20.f;

struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity{ -ballVelocity, -ballVelocity };

    Ball(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(ballRadius, ballRadius);
    }

    void update() {
        shape.move(velocity);

        if (left() < 0)
            velocity.x = ballVelocity;
        else if (right() > windowWidth)
            velocity.x = -ballVelocity;

        if (top() < 0)
            velocity.y = ballVelocity;
        else if (bottom() > windowHeight)
            velocity.y = -ballVelocity;
    }

    float x() const { return shape.getPosition().x; }
    float y() const { return shape.getPosition().y; }
    float left() const { return x() - shape.getRadius(); }
    float right() const { return x() + shape.getRadius(); }
    float top() const { return y() - shape.getRadius(); }
    float bottom() const { return y() + shape.getRadius(); }
};

struct Paddle {
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Paddle(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({ paddleWidth, paddleHeight });
        shape.setFillColor(sf::Color::Blue);
        shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
    }

    void update() {
        shape.move(velocity);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0)
            velocity.x = -paddleVelocity;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < windowWidth)
            velocity.x = paddleVelocity;
        else
            velocity.x = 0;
    }

    float x() const { return shape.getPosition().x; }
    float y() const { return shape.getPosition().y; }
    float left() const { return x() - shape.getSize().x / 2.f; }
    float right() const { return x() + shape.getSize().x / 2.f; }
    float top() const { return y() - shape.getSize().y / 2.f; }
    float bottom() const { return y() + shape.getSize().y / 2.f; }
};

struct Brick {
    sf::RectangleShape shape;
    bool destroyed{ false };

    Brick(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({ brickWidth, brickHeight });
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(brickWidth / 2.f, brickHeight / 2.f);
    }

    float x() const { return shape.getPosition().x; }
    float y() const { return shape.getPosition().y; }
    float left() const { return x() - shape.getSize().x / 2.f; }
    float right() const { return x() + shape.getSize().x / 2.f; }
    float top() const { return y() - shape.getSize().y / 2.f; }
    float bottom() const { return y() + shape.getSize().y / 2.f; }
};

template <typename T1, typename T2>
bool isIntersecting(T1& mA, T2& mB) {
    return mA.right() >= mB.left() && mA.left() <= mB.right() && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void testCollision(Paddle& mPaddle, Ball& mBall) {
    if (!isIntersecting(mPaddle, mBall)) return;

    mBall.velocity.y = -ballVelocity;

    if (mBall.x() < mPaddle.x())
        mBall.velocity.x = -ballVelocity;
    else
        mBall.velocity.x = ballVelocity;
}

void testCollision(Brick& mBrick, Ball& mBall) {
    if (!isIntersecting(mBrick, mBall)) return;

    mBrick.destroyed = true;

    float overlapLeft{ mBall.right() - mBrick.left() };
    float overlapRight{ mBrick.right() - mBall.left() };
    float overlapTop{ mBall.bottom() - mBrick.top() };
    float overlapBottom{ mBrick.bottom() - mBall.top() };

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
    float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

    if (abs(minOverlapX) < abs(minOverlapY))
        mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    else
        mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}

int main() {
    Ball ball{ windowWidth / 2, windowHeight / 2 };
    Paddle paddle{ windowWidth / 2, windowHeight - 50 };

    std::vector<Brick> bricks;

    for (int iX{ 0 }; iX < brickColumns; ++iX) {
        for (int iY{ 0 }; iY < brickRows; ++iY) {
            bricks.emplace_back((iX + 1) * (brickWidth + 3), (iY + 2) * (brickHeight + 3));
        }
    }

    sf::RenderWindow window{ { windowWidth, windowHeight }, "Brick Breaker" };
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        window.clear(sf::Color::Black);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window.close();

        ball.update();
        paddle.update();
        testCollision(paddle, ball);

        for (auto& brick : bricks) {
            testCollision(brick, ball);
        }

        bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
            [](const Brick& mBrick) { return mBrick.destroyed; }),
            std::end(bricks));

        // Check if all bricks are destroyed
        if (bricks.empty()) {
            window.close();
        }

        window.draw(ball.shape);
        window.draw(paddle.shape);

        for (auto& brick : bricks) window.draw(brick.shape);

        window.display();
    }

    return 0;
}
