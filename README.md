# ROS2

# Turtlebot3 e-manual error
- slam map file saver command
$ ros2 run nav2_map_server map_saver_cli -f ~/map

- Execute Navigation 
$ ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=$HOME/map.yaml
