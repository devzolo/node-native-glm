import assert from "node:assert";
import { describe, it } from "node:test";

import exemple from "../index.ts";

describe("Example Test", () => {
	it('exemple.helloMethod() == "world"', () => {
		assert.strictEqual(exemple.helloMethod(), "world");
	});
});
