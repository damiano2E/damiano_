clear()
drawStage(ColorMaker.red)

class BouncingRect(x: Int, y: Int) {
    val pic = Picture.rectangle(60, 60)
    pic.setFillColor(black)
    pic.setPosition(x, y)

    def draw() {
        pic.draw()
    }
}



val br = new BouncingRect(-100, -100)
br.draw()