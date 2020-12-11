# ROS2



# Turtlebot3 e-manual error

- slam map file saver command error
$ ros2 run nav2_map_server map_saver_cli -f ~/map


- Execute Navigation error
$ ros2 launch turtlebot3_navigation2 navigation2.launch.py use_sim_time:=True map:=$HOME/map.yaml

/home/hajung/turtlebot3_ws/src/turtlebot3/turtlebot3/turtlebot3_navigation2/launch/navigation2.launch.py 파일에서 70라인에 하기와 같이 파일명칭에 "nav2_"를 제거해야 함.
PythonLaunchDescriptionSource([nav2_launch_file_dir, '/bringup_launch.py']),


# Moveit
- install : https://moveit.ros.org/install-moveit2/source/
- build : colcon build --event-handlers desktop_notification- status- --cmake-args -DCMAKE_BUILD_TYPE=Release
- example : ros2 launch run_move_group run_move_group.launch.py

# 첨부 파일
- 첨부 2. hyundai_project.zip : 카이스트
- CoBotCommander.zip : 이인국책임
- CoBotCommander2.zip : 이인국책임
