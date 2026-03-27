extends Sprite2D

# when translating into cluige script, don't forget :
#  - register script factory
#  - write instantiate(Dico params) function
#    -- give values to '@export' fields if in 'params'
#    -- use function pointers for 'cluige inheritance equivalence'

@export var speed: float = 3 #cluige characters per second

func _process(delta: float) -> void:
	var dx: float = 0
	var dy: float = 0
	if(Input.is_action_pressed("ui_up")):
		dy -= speed
	if(Input.is_action_pressed("ui_down")):
		dy += speed
	if(Input.is_action_pressed("ui_left")):
		dx -= speed
	if(Input.is_action_pressed("ui_right")):
		dx += speed
	position += Vector2(dx * delta, dy * delta)
