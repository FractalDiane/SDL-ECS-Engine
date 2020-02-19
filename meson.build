project('SDL Test', 'cpp')
deps = [dependency('SDL2'), dependency('SDL2_image')]
src = ['main.cpp', 'Components/Component.cpp', 'Components/SpriteRenderer.cpp', 'Entities/Entity.cpp', 'Entities/TestEntity.cpp']
incs = include_directories('Components', 'Entities', 'System')
executable('SDLTest', src, include_directories: incs, dependencies: deps)
