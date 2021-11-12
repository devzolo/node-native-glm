declare module '@devzolo/node-native-glm' {
    export namespace glm {
        class vec2 {
            x: number;
            y: number;

            constructor(x: number, y: number);
            add(vec: vec2): vec2;
            add(num: number): vec2;

            sub(vec: vec2): vec2;
            sub(num: number): vec2;

            mul(vec: vec2): vec2;
            mul(num: number): vec2;

            div(vec: vec2): vec2;
            div(num: number): vec2;

            copy(): vec3;
        }

        class vec3 {
            x: number;
            y: number;
            z: number;

            constructor(x: number, y: number, z: number);
            add(vec: vec3): vec3;
            add(num: number): vec3;

            sub(vec: vec3): vec3;
            sub(num: number): vec3;

            mul(vec: vec3): vec3;
            mul(num: number): vec3;

            div(vec: vec3): vec3;
            div(num: number): vec3;

            copy(): vec3;
        }

        class mat4 {
            getAsFloat32Array(): any;

            mul(vec: vec3): mat4;
            mul(num: number): mat4;
        }

        function helloWorld(): string;

        function lookAt(position: vec3, target: vec3, up: vec3): mat4;
        function cross(vec1: vec3, vec2: vec3): vec3;
        function normalize(vec: vec3): vec3;
        function radians(degress: number): number;
        function sub(vec1: vec3, vec2: vec3): vec3;
        function add(vec1: vec3, vec2: vec3): vec3;
        function mult(vec1: vec3, vec2: vec3): vec3;
        function perspective(fov: number, aspect: number, near: number, far: number): mat4;
        function translate(mat: mat4, vec: vec3): mat4;
    }
    export default glm;
}
