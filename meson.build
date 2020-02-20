project('SDL Test', 'cpp')
deps = [dependency('SDL2'), dependency('SDL2_image')]
src = [
	'Core/Input.cpp',
	'Core/Window.cpp',
	'Core/World.cpp',
	'Components/Component.cpp',
	'Components/Sprite.cpp',
	'Components/Transform.cpp',
	'Entities/Entity.cpp',
	'Entities/TestEntity.cpp',
	'Systems/PlayerSystem.cpp',
	'Systems/RenderSystem.cpp',
	'main.cpp'
]

incs = include_directories('Core', 'Components', 'Entities', 'Systems')
executable('SDLTest', src, include_directories: incs, dependencies: deps)
