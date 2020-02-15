from  launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            node_namespace='turtlesim1',
            node_executable='turtlesim_node',
            node_name='sim'
        ),
        Node(
            package='turtlesim',
            node_executable='mimic',
            node_name='mimic',
            remappings=[
                ('/input/cmd_vel', '/turtle1/cmd_vel'),
                ('/output/cmd_vel', 'turtlesim1/turtle1/cmd_vel'),
            ]
        ),
#        Node(
#            package='turtlesim',
#            node_executable='turtle_teleop_key',
#            node_name='teleop_turtle'
#        )
    ])
