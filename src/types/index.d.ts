declare module '@devzolo/node-native-glm' {
  export namespace glm {
    class vec2 {
      public x: number;
      public y: number;

      constructor(x: number, y: number);
      public add(vec: vec2): vec2;
      public add(num: number): vec2;

      public sub(vec: vec2): vec2;
      public sub(num: number): vec2;

      public mul(vec: vec2): vec2;
      public mul(num: number): vec2;

      public div(vec: vec2): vec2;
      public div(num: number): vec2;

      public copy(): vec3;
    }

    class vec3 {
      public x: number;
      public y: number;
      public z: number;

      constructor(x: number, y: number, z: number);
      public add(vec: vec3): vec3;
      public add(num: number): vec3;

      public sub(vec: vec3): vec3;
      public sub(num: number): vec3;

      public mul(vec: vec3): vec3;
      public mul(num: number): vec3;

      public div(vec: vec3): vec3;
      public div(num: number): vec3;

      public copy(): vec3;
    }

    class mat4 {
      public getAsFloat32Array(): any;

      public mul(vec: vec3): mat4;
      public mul(num: number): mat4;
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
